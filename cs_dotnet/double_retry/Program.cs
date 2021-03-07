using System;
using System.Threading;
using System.Collections.Generic;
// test recovery case for
//   single failure
//   multimple failure
//   correct reading
//   Device is not responding anymore


namespace double_retry
{
    public class ixgbe_timestamp {
        int fail_at;
        bool failed=false;
        int continous_fails;
        int persistent_after;
        Queue<int> timestamp_queue = new Queue<int>();
        public ixgbe_timestamp(int _fail_at, int _continous_fails, int _persistent_after) {
            fail_at =_fail_at;
            continous_fails = _continous_fails;
            persistent_after = _persistent_after;
        }
        int iteration = 0;

        public int send() {

            DateTime n = DateTime.Now;
            int now_ts = n.Minute * (1000 * 60) + (n.Second * 1000) + n.Millisecond;
            Console.WriteLine("Send Ts: " + now_ts);
            timestamp_queue.Enqueue(now_ts);
            return now_ts;
        }
        public (bool ok,int ts) get_timestamp () {
            // Console.WriteLine("Iteration: " + iteration);
            // Console.WriteLine("FAiled at: " + fail_at + " " + iteration);
            iteration++;
            if (fail_at == iteration) {
                failed = true;
                return (ok: false, ts: 0);
            }

            if(failed && continous_fails != 0) {
                continous_fails--;
                if (continous_fails == 0) {
                    failed = false;
                }
                return (ok: false, ts: 0);
            }

            if (iteration > persistent_after && persistent_after != 0) {
                return (ok: false, ts: 0);
            }

            return (ok: true, ts: timestamp_queue.Dequeue());
        }
    }

    class Program
    {
        static int retry_max = 5;
        private static readonly Random _r = new Random();
        static int timestamps_to_read = 0;
        static int max_past_failed = 10;

        static int get_ts(ref ixgbe_timestamp ixgbe) {
            int _ts = 0;
            int retry = 0;
            
            ++timestamps_to_read;
            if (timestamps_to_read > max_past_failed) {
                Console.WriteLine("Interface does not provide timestamps\nExiting");
                System.Environment.Exit(1);
            }

            while (timestamps_to_read >= 1) {
                Console.WriteLine("Timestamps to read Pre: " + timestamps_to_read + " Current Timestamp to drop: " + _ts);
                while(retry < retry_max){
                    var ts_result = ixgbe.get_timestamp(); //recvmsg
                    if (ts_result.ok) {
                        Console.WriteLine("Tx ts read");
                        _ts = ts_result.ts;
                        break;
                    } else {
                        ++retry;
                        Console.WriteLine("Fail retry: " + retry);
                    }
                }

                if(retry < retry_max) {
                    --timestamps_to_read;
                    Console.WriteLine("Queued timestamps: " + timestamps_to_read);
                    retry = 0;
                } else {
                    Console.WriteLine("BAIL for next cycle\n  Queued timestamps: " + timestamps_to_read);
                    break;
                }
            }

            Console.WriteLine("Timestamps to read Post: " + timestamps_to_read);
            return _ts;
        }

        static void Main(string[] args)
        {
            Console.WriteLine("Test cases:");
            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("AOK-------------------------------");
            ixgbe_timestamp ixgbe_ok = new ixgbe_timestamp(0,0,0);
            for(int i= 0; i<10; ++i) {
                int expected = ixgbe_ok.send();
                int received = get_ts(ref ixgbe_ok);
                Console.WriteLine(i+ ":                  Main Loop Ts:" + received);
                if (expected == received) {
                    Console.WriteLine("OK");
                } else {
                    Console.WriteLine("FAIL");
                }
                Thread.Sleep(1000);
            }

            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Single persistent Failure-------------------");
            ixgbe_timestamp ixgbe_single_per = new ixgbe_timestamp(3,5,0);
            for(int i= 0; i<5; ++i) {
                int expected = ixgbe_single_per.send();
                int received = get_ts(ref ixgbe_single_per);
                Console.WriteLine(i + ":                 Main loop Ts:" + received);
                if (expected == received) {
                    Console.WriteLine("OK");
                } else {
                    Console.WriteLine("FAIL");
                }
                Thread.Sleep(1000);
            }

            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Multiple persistent Failures----------------");
            ixgbe_timestamp ixgbe_multiple_fail = new ixgbe_timestamp(4,15,0);
            for(int i= 0; i<10; ++i) {
                int expected = ixgbe_multiple_fail.send();
                int received = get_ts(ref ixgbe_multiple_fail);
                Console.WriteLine( i + ":                Main Loop Ts:" + received);
                if (expected == received) {
                    Console.WriteLine("OK");
                } else {
                    Console.WriteLine("FAIL");
                }
                Thread.Sleep(1000);
            }
            
            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Permanent Failure---------------------------");
            ixgbe_timestamp ixgbe_permanent = new ixgbe_timestamp(8,0,10);
            for(int i= 0; i<30; ++i) {
                int expected = ixgbe_permanent.send();
                int received = get_ts(ref ixgbe_permanent);
                Console.Write( i + ":                Main Loop Ts:" + received + " : ");
                if (expected == received) {
                    Console.WriteLine("OK");
                } else {
                    Console.WriteLine("FAIL");
                }
                Thread.Sleep(1000);
            }
        }
    }


}



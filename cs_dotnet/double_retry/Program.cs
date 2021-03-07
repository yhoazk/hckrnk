using System;

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
        public ixgbe_timestamp(int _fail_at, int _continous_fails, int _persistent_after) {
            fail_at =_fail_at;
            continous_fails = _continous_fails;
            persistent_after = _persistent_after;
        }
        int timestamp = 0;
        int iteration = 0;
        public (bool ok,int ts) get_timestamp () {
            // Console.WriteLine("Iteration: " + iteration);
            // Console.WriteLine("FAiled at: " + fail_at + " " + iteration);
            iteration++;
            timestamp++;
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

            return (ok: true, ts: timestamp);
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
                Console.WriteLine("Timestamps to read Pre: " + timestamps_to_read);
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

                if(!(retry < retry_max)) {
                    Console.WriteLine("BAIL for next cycle\n  Queued timestamps: " + timestamps_to_read);
                    break;
                } else {
                    --timestamps_to_read;
                    Console.WriteLine("Queued timestamps: " + timestamps_to_read);
                    retry = 0;
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
                Console.WriteLine(i+ ": ++++Main Loop Ts:" + get_ts(ref ixgbe_ok));
            }
            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Single persistent Failure-------------------");
            ixgbe_timestamp ixgbe_single_per = new ixgbe_timestamp(3,5,0);
            for(int i= 0; i<10; ++i) {
                Console.WriteLine(i + ": ++++Main loop Ts:" + get_ts(ref ixgbe_single_per));
            }
            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Multiple persistent Failures----------------");
            ixgbe_timestamp ixgbe_multiple_fail = new ixgbe_timestamp(4,15,0);
            for(int i= 0; i<20; ++i) {
                Console.WriteLine( i + ": ++++Main Loop Ts:" + get_ts(ref ixgbe_multiple_fail));
            }
            Console.WriteLine("--------------------------------------------------------------------------------");
            Console.WriteLine("Permanent Failure---------------------------");
            ixgbe_timestamp ixgbe_permanent = new ixgbe_timestamp(8,0,10);
            for(int i= 0; i<30; ++i) {
                Console.WriteLine(i + ": ++++Main Loop Ts:" + get_ts(ref ixgbe_permanent));
            }
        }
    }


}



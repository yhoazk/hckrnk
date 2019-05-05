# Lock Free Data structures

## What does "lock free" implies

In classic miltithread algorithms whenever data needs to be shared the access
to it must be serialized and operations that change data must appear as atomic
such that no other thead intervenes to spoil data's invariant. Even simple
operations as `++count` must be locked as the `++` is actually 3 steps.
(read, modify, write). In short in lock-based multithreading the programmer
must ensure that any access to data susceptible to race conditions is made
atomic by locking and unlocking a mutex.

The "arbitrarieness" of what can be done while a mutex is locked is what is
problematic. For example wait for I/O operations which will make other threads
to wait for this IO operation also. Evenworse is possible access some other
piece of shared data and attempt to lock its mutex, causing possible dead locks.

In lock free programming you _can't_ do just about anything atomically, only a
small set of operations are atomical. This makes lock-free programmign harder.

But which set of lock-free operations will allow to implement any lock-free
algorithm? Maurice Herlihy showed that atomic operations such as _test-and-set_
 _swap_, _fetch_and_add_ or even atomic queues are insuficcient for properly
synchronizinh more than two threads. On the other side he also gave
universality resuls, proving that some very simple constructs are enough for
implementing any lock-free algorithm for any number of threads.

The simplest ans universal primitive is the CAS (compare and swap):

```cpp
template<class T>
bool CAS(T* addr, T exp, T val){
  if(*addr == exp){
    *addr = val;
    return true;
  }
  return false
}
```

May modern processors implement CAS or equivalent primitives for different bit
lenghts, normally either 32 or 64 bits.

## Wait free, lock free and Locked

* Wait-free:
  * Is a procedure that can complete in a finite number of steps, regardless of
    of the relative speeds of other threads.
* Lock-free:
  * Is a procedure that guarantees progress of at least one of the threads
  executing the procedure. This means that some threads may be delayed.
* Lock-based
  * This tipe of process cannot provide any of the above guarantees, and
  can produce dead and live locks.

Wait and lock free algorithms enjoy more advantages derived from their
definitons:

* Thread-killing immunity: Any thread killd in the system wont delay other
threads
* Signal immunity: Traditionally, routines such as `malloc` can't be called
during signals or async interrupts. This is because the interrupt might occur
right while the routine holds some lock. With lock-free routines, there's no
such problem; theads can freely interleave execution
* Priority inversion immunity: Priority inversion occurs when a low-priority
threar holds a lock to a mutex needed by a hih-priority thread, case in which
the CPU


- - -

[src](https://erdani.com/publications/cuj-2004-10.pdf)

Dead and live locks
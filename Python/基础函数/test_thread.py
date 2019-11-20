#coding:utf_8
import threading
import time
def T1():
    time.sleep(1)
    print('T1 thread finished,current thread {0}'.format(threading.currentThread()))
    
def main():
    add_thread = threading.Thread(target=T1,name="TName")
    add_thread.start()
    add_thread.join()
    print("main thread finished")
if __name__ == '__main__':
    main()

import socket
import threading
import random
import struct

HOST="172.30.119.32"
PORT=7777

random.seed()
start=1000
stop=9999
password=random.randint(start, stop)
print('Server password: ')
print(password)
myLock=threading.Lock()
guessed=False
winner_thread=-1
e=threading.Event()
e.clear()
threads=[]
client_count=0


def reset():
    global myLock, guessed, password, winner_thread, threads, e, client_count
    while True:

        e.wait()
        for i in threads:
            i.join()
        print("Threads are finished. ")
        e.clear()

        myLock.acquire()
        threads=[]
        guessed=False
        winner_thread=-1
        client_count=0

        password=random.randint(start, stop)
        print('Server password: ')
        print(password)
        myLock.release()


def worker(s):
    global myLock, guessed, password, winner_thread, threads, e, client_count

    print('New client, nr ', client_count, 'has connected. Address: ', s.getpeername())

    while not guessed:
        guess=s.recv(4)
        nr=struct.unpack('!I', guess)[0]
        print(nr, '\n')
        if nr==password:
            myLock.acquire()
            guessed=True
            s.sendall(struct.pack('!I', 1))
            winner_thread=threading.get_ident()
            myLock.release()
        else:
            s.sendall(struct.pack('!I', 0))

    if guessed:
        print('Someone won!')
        if threading.get_ident()!=winner_thread:
            s.sendall(struct.pack('!I', 2))
        else:
            print('Winner: ', s.getpeername())




if __name__=='__main__':
    try:
        s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        s.bind((HOST, PORT))
        s.listen(5)
    except socket.error as m:
        print(m.strerror)
        exit()
    t=threading.Thread(target=reset, daemon=True)
    t.start()
    while True:
        client_socket,addrc=s.accept()
        t=threading.Thread(target=worker, args=(client_socket, ))
        threads.append(t)
        client_count+=1
        t.start()

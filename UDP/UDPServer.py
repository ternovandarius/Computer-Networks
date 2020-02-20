import socket

s=socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
s.bind(("172.30.115.236", 777))
buff,addr=s.recvfrom(10)
print (buff)
msg="hello"
s.sendto(msg.encode(), addr)
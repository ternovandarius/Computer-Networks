import socket

s=socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect(("172.30.113.205", 5252))
strr="Ar trebui sa returneze 4."
s.send(strr.encode())
print(s.recv(60))
s.close()

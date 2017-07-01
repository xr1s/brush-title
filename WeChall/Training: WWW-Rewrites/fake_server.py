import socket

server = socket.socket()
server.bind(('0.0.0.0', 80))
server.listen()

client, addr = server.accept()
uri = client.recv(1024).split()[1]
username, command = uri[:-5].split(b'/')[1:]
num1, num2 = map(int, command.split(b'_mul_'))
result = str(num1 * num2).encode()
client.send(b'HTTP/1.1 200 OK\r\n')
client.send(b'Content-Type: text/html\r\n')
client.send(b'Content-Length: %d\r\n' % len(result))
client.send(b'\r\n')
client.send(result)
client.close()


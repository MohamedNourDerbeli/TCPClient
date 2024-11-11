# SimpleTCPClient

## Description
SimpleTCPClient is a basic TCP client implemented in C. It demonstrates how to create a socket, connect to a server over port 80, send an HTTP request, and receive a response. The client sends an HTTP `HEAD` request to a server specified by an IP address and prints the response headers.

This project is designed to help beginners understand the fundamentals of TCP client-side programming.

## Features
- Creates a TCP socket
- Connects to a server over port 80
- Sends an HTTP `HEAD` request
- Receives and prints the server's response
- Handles errors in socket creation, connection, and communication

## Usage
### Compilation
To compile the code, use the following command:
```bash
gcc -o simpletcpclient sockets.c
```

### Execution
To run the program, you need to provide the server's IP address as a command-line argument:
```bash
./simpletcpclient <IP_address>
```

For example:
```bash
./simpletcpclient 93.184.216.34  # IP address for example.com
```

This will send an HTTP `HEAD` request to the server and print the response headers.

## Example Output
```
Connected to 93.184.216.34 on port 80

HTTP/1.1 200 OK
Date: Mon, 11 Nov 2024 12:34:56 GMT
Content-Type: text/html
Content-Length: 1256
Connection: close
...

```

## Requirements
- A C compiler (`gcc` or similar)
- An active internet connection for testing with live servers

## Files
- `sockets.c`: The main C program implementing the TCP client.

## Improvements
- Error handling for partial reads and writes.
- Added a loop to ensure all response data is received and printed.
- Buffer management with a constant for flexibility.


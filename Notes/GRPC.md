1. RPC : Remote Procedure Call : 
   - A protocol that allows a program to execute a procedure on a remote server as if it were a local call.
   - It abstracts the network communication, allowing developers to focus on the logic of the application rather than the details of network communication.
2. gRPC :
   - gRPC is a high-performance, open-source RPC framework developed by Google.
   - It uses HTTP/2 for transport, Protocol Buffers as the interface description language, and provides features like authentication, load balancing, and more.
   - gRPC supports multiple programming languages, making it a versatile choice for building distributed systems.
3. Key Features of gRPC:
   - **HTTP/2**: gRPC uses HTTP/2 for transport, which allows for multiplexing multiple requests over a single connection, reducing latency and improving performance.
   - **Protocol Buffers**: gRPC uses Protocol Buffers (protobuf) as its interface description language, which provides a compact binary format for data serialization. Protbuf : It allows to generate code in multiple languages, ensuring efficient communication between services.
    - **Code generation**: gRPC provides tools to automatically generate client and server code from the service definition, reducing boilerplate code and improving development speed.
   - **Streaming**: gRPC supports both unary (single request/response) and streaming (multiple messages in a single call) communication patterns.
   - **Cross-language support**: gRPC supports multiple programming languages, allowing developers to build services in different languages and still communicate seamlessly.
   - **Built-in authentication and security**: gRPC provides built-in support for authentication and encryption using TLS.
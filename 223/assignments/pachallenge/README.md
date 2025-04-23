# PA Challenge

> Message Middleware

## Running

1. Terminal 1: Run `server`
2. Terminal 2: Run `client_a`
    - Creates a new topic called "Emergency"
    - Waits for Enter to be pressed
3. Terminals 3 & 4: Run `client_b` and `client_c`
    - Clients subscribe to "Emergency"
    - Listens for messages on a separate thread (prints "Waiting for messages...")
4. Terminal 2: Press Enter
    - `client_a` publishes "Snoqualmie Pass closed" to `server`
    - `server` forwards message to "Emergency" subscribers (prints "Message published by Client A, forwarding to subscribers...")
    - Terminals 3 & 4 print "Message received: Snoqualmie Pass closed"

## Works Cited

- [Boost Asio](https://boost.org/doc/libs/1_87_0/doc/html/boost_asio/tutorial.html): TCP connections
- [Boost JSON](https://boost.org/doc/libs/1_87_0/libs/json/doc/html/index.html): Structured requests
- [Boost UUID](https://boost.org/doc/libs/1_87_0/libs/uuid/doc/html/uuid.html): Client IDs

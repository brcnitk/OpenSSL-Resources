## Symmetric Ciphers (Encryption and Decryption)

### Encryption

**To encrypt using Base64**

``openssl enc -base64 -in number.txt``

**To encrypt using aes (interactive)**

``openssl enc -aes-256-cbc -in plain.txt -out encrypted.bin``

**To encrypt using aes (non-interactive)**

``openssl enc -aes-256-cbc -in plain.txt -out encrypted.bin -pass pass:hello``

**To decrypt using aes (interactive)**

``openssl enc -d -aes-256-cbc -in encrypted.bin -out decrypt.txt``

**To decrypt using aes (encryption password "hello" entered at the command prompt)**

``openssl enc -d -aes-256-cbc -in encrypted.bin -out decrypt.txt -pass pass:hello``

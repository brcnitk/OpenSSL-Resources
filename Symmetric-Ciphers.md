## Symmetric Ciphers (Encryption and Decryption)

### Base64

**Encryption**

``openssl enc -base64 -in number.txt``

### Data Encryption Standard (DES)



### Advanced Encryption Standard (AES)

**Encryption** (Interactive)

``openssl enc -aes-256-cbc -in plain.txt -out encrypted.bin``

**Encryption** (non-interactive)

``openssl enc -aes-256-cbc -in plain.txt -out encrypted.bin -pass pass:hello``

**Decryption** (interactive)

``openssl enc -d -aes-256-cbc -in encrypted.bin -out decrypt.txt``

**Decryption** (non-interactive)

``openssl enc -d -aes-256-cbc -in encrypted.bin -out decrypt.txt -pass pass:hello``


## Hash Function

> - A hash function maps a variable-length message into a fixed-length hash value, or message digest.
> - The kind of hash function needed for security applications is referred to as a cryptographic hash function.
> - Message Authentication: 
> - Message authentication is a mechanism or service used to verify the integrity of a message. Message authentication assures that data received are exactly as sent (i.e., contain no modification, insertion, deletion, or replay).
> - When a hash function is used to provide message authentication, the hash function value is often referred to as a message digest.
> - More commonly, message authentication is achieved using a message authentication code (MAC), also known as a keyed hash function.
> - In recent years, the most widely used hash function has been the Secure Hash Algorithm (SHA).

## Message Digest (MD)

**MD5 digest**

```
Method 1:
openssl dgst -md5 input.txt
```
```
Method 2: 
md5sum input.txt
```

## Secure Hash Algorithm (SHA)

**SHA1 digest**

```
Method 1: 
openssl dgst -sha1 filename
```

```
Method 2: 
sha1sum input.txt
```

**SHA256 digest**

``openssl dgst -sha256 filename``

**To generate and sign a digest** (it means encrypting digest using private key)

``openssl dgst -sha256 -sign private.pem -out input.sha1 input.txt``

**To verify signed digest** (it means decrypting digest using public key)

``openssl dgst -sha256 -verify pubkey.pem -signature input.sha1 input.txt``

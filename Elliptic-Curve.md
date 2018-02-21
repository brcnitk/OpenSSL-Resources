## Elliptic Curve Cryptography

**Generate private key**

``openssl ecparam -name secp256k1 -genkey -noout -out PRa.pem``

**Extract public key**

``openssl ec -in private.pem -pubout -out PUa.pem``

#There are no tools for encrypting and decrypting! ECC doesn’t define these directly. 
#Instead, ECC users use Diffie-Hellman (DH) key exchange to compute a shared secret, then communicate using that shared secret. 
#This combination of ECC and DH is called ECDH.

**Generating scerete key**

``openssl pkeyutl -derive -inkey PRa.pem -peerkey PUb.pem -out SKa.bin``

#Alice and Bob derive their shared secret:

openssl pkeyutl -derive -inkey alice_priv_key.pem -peerkey bob_pub_key.pem -out alice_shared_secret.bin
openssl pkeyutl -derive -inkey bob_priv_key.pem -peerkey alice_pub_key.pem -out bob_shared_secret.bin

# To check if keys are same
$ cmp alice_shared_secret.bin bob_shared_secret.bin

#Display shared keys
$ base64 alice_shared_secret.bin

$ base64 bob_shared_secret.bin


# Plaintext
$ echo 'Message for Bob' > plain.txt

#Encrypt Decrypt using symmetric cipher
$ openssl enc -aes256 -base64 -k $(base64 alice_shared_secret.bin) -e -in plain.txt -out cipher.txt
$ openssl enc -aes256 -base64 -k $(base64 bob_shared_secret.bin) -d -in cipher.txt -out plain_again.txt

#Display Decrypted text
$ cat plain_again.txt

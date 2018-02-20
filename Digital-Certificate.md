Setup:


                                server.csr, server.key
Certificate Authority (CA) <------------------------------  Server (User)
                           ------------------------------>
                                     server.cert



### Generating Certificate Signing Request (CSR)
--------------------------------------------

Step 1.1: Generate the keys for the Certificate Signing Request (CSR)

**Private key with password**

``openssl genrsa -des3 -out server.key 2048``

**Private key without password**

``openssl genrsa -out server.key 2048``

**Encrypt private key which is without password**

``openssl rsa -des3 -in server.key -out encrypted.key``

**Decrypting passord protected private key**

``openssl rsa -in server.key -out server.key.insecure``
``mv server.key server.key.secure``
``mv server.key.insecure server.key``

**Verify private key (Display the private key)**

``openssl rsa -check -in server.key``

**View private key**

``openssl rsa -in server.key -noout -text``

**Extracting public key (optional)**

``openssl rsa -in server.key -pubout -out server.pubkey``

**View public key (optional)**

``openssl rsa -in server.pubkey -pubin -noout -text``

Step 1.2: Certificate Signing Request (CSR)

**Create CSR (with existing private key)**

``openssl req -new -key server.key -out server.csr``

**Create CSR (without existing private key)**

``openssl req -newkey rsa:2048 -nodes -keyout server.key -out server.csr``

**Create CSR (with existing private key and certificate). For renewing an existing certificate but you or your CA do not have the original CSR**

``openssl x509 -in server.cert -signkey server.key -x509toreq -out server.csr``

**Non-interactive way to generate CSR**

``-subj "/C=US/ST=New York/L=Brooklyn/O=Example Brooklyn Company/CN=examplebrooklyn.com"``

**View CSR**

``openssl req -text -noout -in server.csr``

**View and verify CSR (domain.csr) entries**

``openssl req -text -noout -verify -in server.csr``

### Creating Self-Signed Certificate (User)
---------------------------------------

**Create self-signed certificate (with private key and csr)**

``openssl x509 -req -days 365 -in server.csr -signkey server.key -out server.cert``

**Create self-signed certificate. (without private key and CSR)**

``openssl req -newkey rsa:2048 -nodes -keyout server.key -x509 -days 365 -out domain.cert``

**Create self-signed certificate (with private key and without CSR)**

``openssl req -key server.key -new -x509 -days 365 -out server.cert``

**View certificate**

``openssl x509 -text -noout -in server.cert``

**Verify a private key (domain.key) matches a certificate (domain.crt) and CSR (domain.csr)**

``openssl rsa -noout -modulus -in server.key | openssl md5``
``openssl x509 -noout -modulus -in server.cert | openssl md5``
``openssl req -noout -modulus -in server.csr | openssl md5``

### Installing the Certificate (User)
---------------------------------

**/etc/ssl/certs - location of certificate and /etc/ssl/private - location of private key**

``sudo cp server.crt /etc/ssl/certs``
``sudo cp server.key /etc/ssl/private``

### Certificate Authority (CA)
--------------------------

**First, create the directories to hold the CA certificate and related files**

``sudo mkdir /etc/ssl/CA``
``sudo mkdir /etc/ssl/newcerts``

**The CA needs a few additional files to operate, one to keep track of the last serial number used by the CA, each certificate must have a unique serial number, and another file to record which certificates have been issued**

``sudo sh -c "echo '01' > /etc/ssl/CA/serial"``
``sudo touch /etc/ssl/CA/index.txt``

**The third file is a CA configuration file. Though not strictly necessary, it is very convenient when issuing multiple certificates. Edit /etc/ssl/openssl.cnf, and in the [ CA_default ] change:**

``dir             = /etc/ssl``              # Where everything is kept
``database        = $dir/CA/index.txt``     # database index file.
``certificate     = $dir/certs/ca.cert``    # The CA certificate
``serial          = $dir/CA/serial``        # The current serial number
``private_key     = $dir/private/ca.key``   # The private key

**Next, create the self-signed root certificate:**

``openssl req -new -x509 -extensions v3_ca -keyout ca.key -out ca.cert -days 3650``

**Now install the root certificate and key:**

``sudo mv ca.key /etc/ssl/private/``
``sudo mv ca.cert /etc/ssl/certs/``

*********************************************************************************************************************************

### Creating Certificate signed by CA
---------------------------------

**Certificate signed by CA (server.csr - CSR of a user)**

``sudo openssl ca -in server.csr -config /etc/ssl/openssl.cnf``

**Certificate signed by CA**

``openssl x509 -req -in server.csr -out server.cert -signkey server.key -CA ca.cert -CAkey ca.key -CAcreateserial -days 365``

**View certificate**

``openssl x509 -text -noout -in server.cert``

**Verify certificate was signed by a CA**

``openssl verify -verbose -CAFile ca.cert server.cert``

### Certificate of Different format
-------------------------------

**Convert a certificate format PEM to DER**

``openssl x509 -in server.cert -outform der -out domain.der``

**Convert a certificate format DER to PEM**

``openssl x509 -inform der -in domain.der -out server.cert``

### References:

**A. Website:**

1. [Digitalocean.com](https://goo.gl/Qokp8m)
2. https://blog.didierstevens.com/2008/12/30/howto-make-your-own-cert-with-openssl/
3. https://gist.github.com/Soarez/9688998
4. [Ubuntu Website](https://help.ubuntu.com/lts/serverguide/certificates-and-security.html)

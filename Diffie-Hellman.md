KAB = axA.xB mod q
= yAxB mod q  (which B can compute) 
= yBxA mod q  (which A can compute)

Steps for Diffie-Hellman Key Exchange with OpenSSL
---------------------------------------------------------

1.Generate the Diffie-Hellman global public parameters, saving them in the file dhp.pem:

$ openssl genpkey -genparam -algorithm DH -out dhp.pem

2.Display the generated global public parameters, first in the encoded form, then in the text form:

encoded form :- $ cat dhp.pem

text form :- $ openssl pkeyparam -in dhp.pem -text

3.Each user now uses the public parameters to generate their own private and public key, saving them in the file dhkey1.pem (for user 1) and dhkey2.pem (for user 2): 

$ openssl genpkey -paramfile dhp.pem -out dhkey1.pem
$ openssl pkey -in dhkey1.pem -text -noout

4.The other user uses the same public parameters, dhp.pem, to generate their private/public key: 

$ openssl genpkey -paramfile dhp.pem -out dhkey2.pem
$ openssl pkey -in dhkey2.pem -text -noout

5. The users must exchange their public keys. First extract the public key into the file dhpub1.pem (and similar user 2 creates dh2pub.pem - this step is not shown below): 

$ openssl pkey -in dhkey1.pem -pubout -out dhpub1.pem

$ openssl pkey -pubin -in dhpub1.pem -text 

6.After exchanging public keys, i.e. the files dhpub1.pem and dhpub2.pem, each user can derive the shared secret. User 1 performs the following to output the secret, a 128 Byte binary value into the file secret1.bin: 

$ openssl pkeyutl -derive -inkey dhkey1.pem -peerkey dhpub2.pem -out secret1.bin

7.The other user does the same using their private key and user 1's public key to produce secret2.bin: 

$ openssl pkeyutl -derive -inkey dhkey2.pem -peerkey dhpub1.pem -out secret2.bin

8.To copy files from your local machine to a remote machine, use the following command syntax.

$ rcp source machinename:destination

9.The secrets should be the same: 
$ cmp secret1.bin secret2.bin
$ xxd secret1.bin
$ xxd secret.bin

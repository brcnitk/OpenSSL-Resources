## Diffie-Hellman Key Exchange

**Global public parameters** (Common for both users)

``$ openssl genpkey -genparam -algorithm DH -out dhp.pem``

**View global parameters**

```
$ cat dhp.pem
$ openssl pkeyparam -in dhp.pem -text
```

**Private key**

``$ openssl genpkey -paramfile dhp.pem -out PRa.pem``

**View private key**

``$ openssl pkey -in PRa.pem -text -noout``

**Public key**

``$ openssl pkey -in PRa.pem -pubout -out PUa.pem``

**View public key**

``$ openssl pkey -pubin -in PUa.pem -text``

**Secrete key**

``$ openssl pkeyutl -derive -inkey PRa.pem -peerkey PUb.pem -out SKa.bin``

**View secrete key**

``$xxd SKa.bin``

**Compare secrete key**

`$cmp SKa.bin SKb.bin``

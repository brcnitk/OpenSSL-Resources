## OpenSSL Basics

**OpenSSL Version**

``openssl version``

``openssl version -a``

``openssl version -help``

**OpenSSL Available Commands**

``openssl -help``

> "Standard commands" list available utilities. Linux "man" command display the manual page of utility. (eg. man ciphers)

> "Message Digest commands" list all message digest commands.

> "Cipher commands" list all cipher commands.

**List of cipher suites**

``openssl ciphers -v``

**Performance**

As you’re probably aware, computation speed is a significant limiting factor for any cryptographic operation. OpenSSL comes with a built-in benchmarking tool that you can use to get an idea about a system’s capabilities and limits. You can invoke the benchmark using the ``speed`` command.

``openssl speed``

**Connecting to SSL service**

``openssl s_client -connect www.feistyduck.com:443``

In case of verify error:num=19:self signed certificate in certificate chain,

``openssl s_client -connect www.feistyduck.com:443 -CAfile /etc/ssl/certs/ca-certificates.crt``

**View CAs certificate**

``openssl s_client -connect www.feistyduck.com:443 -showcerts``

**Testing protocol support**

To test -ssl2 , -ssl3 , -tls1 , -tls1_1 , or -tls1_2 protocol support,

``openssl s_client -connect www.example.com:443 -tls1_2``

**Testing cipher suite support**

``openssl s_client -connect www.feistyduck.com:443 -cipher RC4-SHA``

## References:

1. "OpenSSL Coockbook", by Ivan Ristić

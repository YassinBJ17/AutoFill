# Certificates

There are two types of certificates we use.

The ROOT CA is unique and used to signed other certificates.

The other certificates are self-sustainables after being signed by the ROOT CA,
as long as the target HW is able to authenticate them with the ROOT CA's public
key.

## ROOT CA

gen_root.sh - Create a ROOT Certificate Authority

### Description

The ROOT CA is used to sign other certificates and shall be unique
to all softwares in a given project.

### Synopsis

The gen_root.sh script will create a new self-signed ROOT CA in
the `ROOT_CERT` folder.

### Outputs

The script will output multiple files, here is a description of
each file.

#### ROOT Certificate

`DEV_ROOT_Certificate.pem` is the self-signed certificate containing information
about the issuer.

Information it contains can be displayed using:

```bash
openssl x509 -noout -text -in DEV_ROOT_Certificate.pem
```

#### Private Key

`DEV_ROOT_PrivateKey.pem` is the file used to sign other certificates.

Information it contains can be displayed using:

```bash
openssl rsa -noout -text -in DEV_ROOT_PrivateKey.pem
```

#### Public Key

`DEV_ROOT_PublicKey.der` is the file used to verify a certificate is signed
with our ROOT CA.

This is the file we need to ship in the project to verify the certificates.

## Certificates

gen_cert.sh - Create a Certificate and sign it with the ROOT CA

### Description

The certificate is used to sign different kind of data.

### Synopsis

The gen_cert.sh script will create a new certificate and sign it with.

### Inputs

#### ROOT CA

You may provide the path to the ROOT CA needed to sign the certificate.
The input directory need to contain files named `DEV_ROOT_Certificate.pem`
and `DEV_ROOT_PrivateKey.pem`

### Outputs

The script will output multiple files in a new timestamped directory, here is a
description of each file.

#### Certificate

`DEV_Certificate.pem` is the ROOT CA signed certificate containing information
about the issuer.

Information it contains can be displayed using:

```bash
openssl x509 -noout -text -in DEV_Certificate.pem
```

#### Private Key

`DEV_PrivateKey.pem` is the file used to sign data.

Information it contains can be displayed using:

```bash
openssl rsa -noout -text -in DEV_PrivateKey.pem
```

Data can be signed using this commands:

```bash
openssl dgst -sign DEV_PrivateKey.pem -keyform PEM -sha256 -out data.bin.sign -binary data.bin
```

or:

```bash
openssl dgst -binary -sha256 data.bin > hash.bin
openssl pkeyutl -sign -in hash.bin -inkey DEV_PrivateKey.pem -pkeyopt digest:sha256 -keyform PEM -out data.bin.sign
```

In order to verify the data, one may extract the public key from the
certificate and use it to verify the signature:

```bash
openssl x509 -pubkey -noout -in DEV_Certificate.pem -out DEV_PublicKey.pem

openssl dgst -verify DEV_PublicKey.pem -keyform PEM -sha256 -signature data.bin.sign -binary data.bin
```

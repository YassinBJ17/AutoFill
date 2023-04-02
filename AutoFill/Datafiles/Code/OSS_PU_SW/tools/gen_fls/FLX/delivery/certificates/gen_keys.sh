#!/bin/sh

# Note: This is probably temporary as long as we do know how to generate an 'official' .SKF file

printf -v gen_date '%(%Y%m%d%H%M%S)T' -1
GEN_DIR=CERT_$gen_date

KEY_FILE=$GEN_DIR/DEV_PrivateKey.pem
PRV_FILE=$GEN_DIR/DEV_PrivateKey.der
PUB_FILE=$GEN_DIR/DEV_PublicKey.pem

mkdir -p $GEN_DIR

#Create RSA key
openssl genrsa -out $KEY_FILE 4096

#Convert private key to DER
openssl rsa -outform DER -in $KEY_FILE -out $PRV_FILE

#Extract public key
openssl rsa -in $KEY_FILE -out $PUB_FILE -pubout

echo "DONE"

#!/bin/sh

CERT_SUBJECT="/C=FR/ST=FRANCE/L=Eragny/O=Safran Group/OU=SED/CN=SkyNaute OPER Certificate"
CERT_VALIDITY_DAYS=3600
LABEL=oper-1.4.0

ROOT_CERT_DIR=ROOT_CERT

if [ "$#" -gt 0 ];
then
    ROOT_CERT_DIR=$1
fi

PKCS11_MODULE=/usr/lib/x86_64-linux-gnu/opensc-pkcs11.so

ROOT_CERT_ASN1_FILE=$ROOT_CERT_DIR/DEV_ROOT_Certificate2.der
ROOT_CERT_FILE=$ROOT_CERT_DIR/DEV_ROOT_Certificate2.pem
#ROOT_KEY_PRIV_FILE=$ROOT_CERT_DIR/DEV_ROOT_PrivateKey.pem
#ROOT_SRL_FILE=$ROOT_CERT_DIR/DEV_ROOT_Certificate.srl

printf -v gen_date '%(%Y%m%d%H%M%S)T' -1
GEN_DIR=CERT_$gen_date

CERT_FILE=$GEN_DIR/DEV_Certificate2.pem
#KEY_FILE=$GEN_DIR/DEV_PrivateKey.pem

CSR_FILE=$GEN_DIR/DEV_CertificateSigningRequest.csr

# If running on bash for Windows, any argument starting with a forward slash is automatically
# interpreted as a drive path. To stop that, you can prefix with 2 forward slashes instead
# of 1 - but in the specific case of openssl, that causes the first CN segment key to be read as
# "/C" instead of "C", and is skipped. We work around that by prefixing with a spurious segment,
# which will be skipped by openssl
function fixup_cn_subject() {
    local result="${1}"
    case $OSTYPE in
        msys|win32) result="//XX=x${result}"
    esac
    echo "$result"
}

mkdir -p $GEN_DIR

# Fix Subjects for windaube
CERT_SUBJECT=$(fixup_cn_subject "$CERT_SUBJECT")

# Create RSA key
pkcs11-tool --module $PKCS11_MODULE --login --keypairgen --key-type rsa:4096 --label $LABEL

# Configure openssl engine
#openssl engine -t dynamic -pre SO_PATH:$PKCS11_ENGINE -pre ID:pkcs11 -pre LIST_ADD:1 -pre LOAD -pre MODULE_PATH:$PKCS11_MODULE

# Create a CSR (Certificate Signing Request)
openssl req -engine pkcs11 -new -sha256 --key "pkcs11:object=oper-1.4.0;type=private" -keyform engine -out $CSR_FILE -subj "$CERT_SUBJECT"

# Get the root certificate from SmartCard-HSM
pkcs11-tool --module $PKCS11_MODULE --login --read-object --output-file $ROOT_CERT_ASN1_FILE --type cert --label "skynaute-prod-root"

# Convert the certificate from DER format to PEM format
openssl x509 -text -inform DER -in $ROOT_CERT_ASN1_FILE -outform PEM -out $ROOT_CERT_FILE

# Create a certificate signed
openssl x509 -engine pkcs11 -req -in $CSR_FILE -CA $ROOT_CERT_FILE -CAkey "pkcs11:object=skynaute-prod-root" -CAkeyform engine -CAcreateserial -out $CERT_FILE -days $CERT_VALIDITY_DAYS -sha256
#Notes: Only use CAcreateserial for the first sub-certificate

rm -f $ROOT_SRL_FILE
rm -f $CSR_FILE

echo "DONE"

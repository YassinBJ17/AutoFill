#!/bin/sh

CERT_SUBJECT="/C=FR/ST=FRANCE/L=Eragny/O=Safran Group/OU=SED/CN=SkyNaute DEV Certificate"
CERT_VALIDITY_DAYS=3600

ROOT_CERT_DIR=ROOT_CERT

if [ "$#" -gt 0 ];
then
    ROOT_CERT_DIR=$1
fi

ROOT_CERT_FILE=$ROOT_CERT_DIR/DEV_ROOT_Certificate.pem
ROOT_KEY_PRIV_FILE=$ROOT_CERT_DIR/DEV_ROOT_PrivateKey.pem
ROOT_SRL_FILE=$ROOT_CERT_DIR/DEV_ROOT_Certificate.srl

printf -v gen_date '%(%Y%m%d%H%M%S)T' -1
GEN_DIR=CERT_$gen_date

CERT_FILE=$GEN_DIR/DEV_Certificate.pem
KEY_FILE=$GEN_DIR/DEV_PrivateKey.pem

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

#Create RSA key
openssl genrsa -out $KEY_FILE 4096

#Create a CSR (Certificate Signing Request)
openssl req -new -sha256 -key $KEY_FILE -out $CSR_FILE -subj "$CERT_SUBJECT"

if [ -f $ROOT_CERT_FILE -a -f $ROOT_KEY_PRIV_FILE ]; then
    openssl x509 -req -in $CSR_FILE -CA $ROOT_CERT_FILE -CAkey $ROOT_KEY_PRIV_FILE -CAcreateserial -out $CERT_FILE -days $CERT_VALIDITY_DAYS -sha256
    #Notes: Only use CAcreateserial for the first sub-certificate
    rm -f $ROOT_SRL_FILE
else
    echo 'ROOT CERT not found' >&2
fi

rm -f $CSR_FILE

echo "DONE"

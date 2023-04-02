#!/bin/sh

ROOT_CERT_SUBJECT="/C=FR/ST=FRANCE/L=Eragny/O=Safran Group/OU=SED/CN=SkyNaute DEV Root Certificate"
ROOT_CERT_VALIDITY_DAYS=3650

GEN_DIR=ROOT_CERT

ROOT_CERT_FILE=$GEN_DIR/DEV_ROOT_Certificate.pem
ROOT_KEY_PRIV_FILE=$GEN_DIR/DEV_ROOT_PrivateKey.pem
ROOT_KEY_PUB_FILE=$GEN_DIR/DEV_ROOT_PublicKey.pem
ROOT_KEY_PUB_ASN1_FILE=$GEN_DIR/DEV_ROOT_PublicKey.der

# DO NOT EDIT BELLOW THIS COMMENT

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

function yes_or_no {
    while true; do
        read -p "$* [y/n]: " yn
        case $yn in
            [Yy]*) return 0  ;;  
            [Nn]*) echo "Aborted" ; return  1 ;;
        esac
    done
}

echo "You are about to create a *NEW* ROOT certificate. You will need to import the new certificate to the target."
yes_or_no "Is it really what you want to do?" || exit 0

mkdir -p $GEN_DIR

# Fix Subjects for windaube
ROOT_CERT_SUBJECT=$(fixup_cn_subject "$ROOT_CERT_SUBJECT")

#Create a new auto-signed certificate and private key
openssl req -x509 -newkey rsa:4096 -nodes -keyout $ROOT_KEY_PRIV_FILE -days $ROOT_CERT_VALIDITY_DAYS -out $ROOT_CERT_FILE -subj "$ROOT_CERT_SUBJECT"

#Extract public key from certificate
openssl x509 -pubkey -noout -in $ROOT_CERT_FILE -out $ROOT_KEY_PUB_FILE

#Convert public key to DER (ASN1)
openssl enc -d -a -in $ROOT_KEY_PUB_FILE -out $ROOT_KEY_PUB_ASN1_FILE

rm -f $ROOT_KEY_PUB_FILE

echo "DONE"

#!/bin/sh

ROOT_CERT_SUBJECT="/C=FR/ST=FRANCE/L=Eragny/O=Safran Group/OU=SED/CN=SkyNaute PROD Root Certificate"
ROOT_CERT_VALIDITY_DAYS=3650
LABEL=skynaute-prod-root
#SLOTID=0
#KEYID=28c2b023cf70e1810615aa851319b124706b6ac7

GEN_DIR=/home/ubuntu/Documents/ROOT_CERT

PKCS11_MODULE=/usr/lib/x86_64-linux-gnu/opensc-pkcs11.so
PKCS11_ENGINE=/usr/lib/x86_64-linux-gnu/engines-1.1/libpkcs11.so

ROOT_CERT_FILE=$GEN_DIR/DEV_ROOT_Certificate.pem
ROOT_CERT_ASN1_FILE=$GEN_DIR/DEV_ROOT_Certificate.der
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

# Create RSA key
pkcs11-tool --module $PKCS11_MODULE --login --keypairgen --key-type rsa:4096 --label $LABEL

# Configure openssl engine
#openssl engine -pre SO_PATH:$PKCS11_ENGINE -pre ID:pkcs11 -pre LIST_ADD:1 -pre LOAD -pre MODULE_PATH:$PKCS11_MODULE -t dynamic
#
#ne fonctionne pas (il faut passer en mode console openssl probablement).
#=> la solution est d'éditer le fichier /etc/ssl/openssl.cnf (sudo gedit /etc/ssl/openssl.cnf) et d'ajouter au début du fichier:
#
#openssl_conf = openssl_init
#
#ET A LA FIN DU FICHIER
#
#[openssl_init]
#engines=engine_section
#
#[engine_section]
#pkcs11 = pkcs11_section
#
#[pkcs11_section]
#engine_id = pkcs11
#dynamic_path = /usr/lib/x86_64-linux-gnu/engines-1.1/libpkcs11.so
#MODULE_PATH  = /usr/lib/x86_64-linux-gnu/opensc-pkcs11.so
#init = 0

# Create an auto-signed certificate
openssl req -engine pkcs11 -new -key "pkcs11:object=skynaute-prod-root;type=private" -keyform engine -out $ROOT_CERT_FILE -text -x509 -days $ROOT_CERT_VALIDITY_DAYS -subj "$ROOT_CERT_SUBJECT"

# Convert cert in DER (ASN1)
openssl x509 -in $ROOT_CERT_FILE -out $ROOT_CERT_ASN1_FILE -outform der

# Store the certificate into the SmartCard-HSM
pkcs11-tool --module $PKCS11_MODULE --login --write-object $ROOT_CERT_ASN1_FILE --type cert --label "skynaute-prod-root"


#Extract public key from certificate
openssl x509 -pubkey -noout -in $ROOT_CERT_FILE -out $ROOT_KEY_PUB_FILE

#Convert public key to DER (ASN1)
openssl enc -d -a -in $ROOT_KEY_PUB_FILE -out $ROOT_KEY_PUB_ASN1_FILE

rm -f $ROOT_KEY_PUB_FILE

# Store the public key into the SmartCard-HSM
#pkcs11-tool --module $PKCS11_MODULE --login --write-object $ROOT_KEY_PUB_ASN1_FILE --type pubkey --label "skynaute-prod-root"
#inutile elle est déjà dedans quand on créé la paire de clé RSA (ça écrase la clé publique déjà existante)

echo "DONE"

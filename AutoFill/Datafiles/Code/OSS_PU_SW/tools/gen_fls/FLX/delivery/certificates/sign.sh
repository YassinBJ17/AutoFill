
# Inputs
KEY_FILE=DEV_PrivateKey.pem
FILE_TO_SIGN=SIF_header.B64
CONFIG_ASN1=asn1.conf

# Outputs
SIGNATURE=SIF_header.SIGN

# Sign SIF header
openssl dgst -sign $KEY_FILE -keyform PEM -sha256 -out $SIGNATURE -binary $FILE_TO_SIGN

# Add ASN1 sequence
sed "s/%DATA%/$(xxd -ps -c 512 ${SIGNATURE})/g" $CONFIG_ASN1 > ${SIGNATURE}.ASN1.conf
openssl asn1parse -noout -genconf ${SIGNATURE}.ASN1.conf -out ${SIGNATURE}.ASN1

# Convert in base64
base64 -w 64 ${SIGNATURE}.ASN1 > ${SIGNATURE}.ASN1.B64

# Remove temporary file
rm -f ${SIGNATURE}.ASN1.conf ${SIGNATURE}.ASN1
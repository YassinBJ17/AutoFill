
# Inputs
PUB_FILE=PublicKey.pem

# Outputs
AES_FILE=aes_key.bin

# Generation of AES key
openssl rand –out $AES_FILE 32

# Encrypt AES key using pub key
openssl rsautl -encrypt -pubin -inkey $PUB_FILE -in $AES_FILE -out ${AES_FILE}.ENC

# Convert in base64
base64 -w 64 ${AES_FILE}.ENC > ${AES_FILE}.ENC.B64
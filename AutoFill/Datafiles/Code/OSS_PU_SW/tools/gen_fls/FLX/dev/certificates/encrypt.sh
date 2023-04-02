
# inputs
DATA_FILE=data.LUP
AES_FILE=aes_key.bin

# outputs
IV_FILE=initial_vector.bin


# Generate initial vector
openssl rand –out $IV_FILE 16

# Encrypt data file
aes_key=`xxd -ps -c 512 ${AES_FILE}`
iv=`xxd -ps -c 512 ${IV_FILE}`
openssl enc -aes-256-cbc -in $DATA_FILE -K $aes_key -iv $iv -out ${DATA_FILE}.ENC

# Add IV at the beginning of the encrypted file to get the SEF file
cat $IV_FILE ${DATA_FILE}.ENC > ${DATA_FILE}.SEF

# Remove temporary file
rm -f ${DATA_FILE}.ENC
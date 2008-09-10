TARBALL="http://perso.epitech.net/~vieux_v/API/zenziapi.tar"
DESTINATION="api/"

FILE=${TARBALL##*/};

echo "
#### Create API directory if not exist ####
" && \
    mkdir $DESTINATION;
echo "
#### Go to API directory ####
" && \
    cd $DESTINATION && \
    echo "
#### Empty directory ####
" && \
    rm -rfv * && \
    echo "
#### Download API ####
" && \
    wget $TARBALL && \
    echo "
#### Detar API ####
" && \
    tar xfv $FILE && \
    echo "
#### Remove tar ####
" && \
    rm -rfv $FILE && \
    echo "
#### Reback ####
" && \
    cd - && \
    echo "
#### End #### \
";

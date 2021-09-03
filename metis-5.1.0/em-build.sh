emcc -o metis.js -O3 -s WASM=1 \
	--no-entry \
	-s ALLOW_MEMORY_GROWTH=1 \
    -DNDEBUG \
	-I include \
	-I GKlib \
	-I libmetis \
    wasm.c \
    ./{GKlib,libmetis}/*.c
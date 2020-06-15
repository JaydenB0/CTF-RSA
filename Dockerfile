FROM alpine:latest
COPY ./src/ /usr/src/CTF-RSA
WORKDIR /usr/src/CTF-RSA

RUN mkdir build

RUN apk add gmp-dev make g++ boost-program_options boost-dev
RUN make
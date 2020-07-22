# CTF-RSA (WIP)
CTF Framework for RSA Cryptography

![HitCount](http://hits.dwyl.io/JaydenB0/CTF-RSA.svg)

![License](https://img.shields.io/github/license/JaydenB0/CTF-RSA?style=flat-square)

![Stars](https://img.shields.io/github/stars/JaydenB0/CTF-RSA?style=for-the-badge)
### Planned Features

- Calculate missing variables
- Perform common attacks

### Purpose
The purpose of this framework is to make solving cryptography problems involving RSA as easy and **intuitive** as possible.

### Build
Compile this framework by running `make` on the `makefile` located in the `src` directory.
If you are using VSCode, run the build task while in the [developer container](https://code.visualstudio.com/docs/remote/containers).

### Running
To run this framework, just execute the binary located in the build directory with the given integers as flags like:

```
./ctfrsa -p <INT> -q <INT>
./ctfrsa -h
./ctfrsa -c <INT< -d <INT> -n <INT>
```
To run the binary in Docker, launch an interactive shell using `docker run -it --rm ctfrsa`


### TODO (AS OF 4/15/2020)
- More efficient var checking
- Faster and cleaner and modular code

If you've found this framework useful, please star and pass the word on!

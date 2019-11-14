# Wheel of Misfortune

📖A two-player word game which involves an "AI" with optimal strategy.

## Getting Started

### Prerequisites

* GCC
* Shell (Bash is recommended)

### Download source code and compile
The following instructions are presented using Bash in macOS:
```
# Change to HOME directory
$ cd ~

# Clone this repo and 'cd' into it
$ git clone https://github.com/kevinxu993/Wheel-of-Misfortune.git
$ cd Wheel-of-Misfortune/

# Let's compile.
$ make
gcc -Wall -g -std=gnu99  -c wheel.c
gcc -Wall -g -std=gnu99  -c family.c
gcc -Wall -g -std=gnu99  -c reading.c
gcc -Wall -g -std=gnu99  -o wheel wheel.o family.o reading.o
```

### Usage
```
Usage: wheel
```

## Family and wordlist data structure
![data structure](https://user-images.githubusercontent.com/25379724/53540528-eaa24100-3ae3-11e9-8c7d-f87b63a2f905.png)

## Examples
```
$ ./wheel 
Length of words to use? 5
How many guesses would you like?
Choose a number between 1 and 26: 5
Guesses remaining: 5
Word: -----
Next guess? a
There is no a in the word.
Guesses remaining: 4
Word: -----
Next guess? b
There is no b in the word.
Guesses remaining: 3
Word: -----
Next guess? c
There is no c in the word.
Guesses remaining: 2
Word: -----
Next guess? d
There is no d in the word.
Guesses remaining: 1
Word: -----
Next guess? e
There is no e in the word.
You lose! The word was slump.
Play another round (y/n)? n

$ ./wheel 
Length of words to use? 20
How many guesses would you like?
Choose a number between 1 and 26: 26
Guesses remaining: 26
Word: --------------------
Next guess? q
There is no q in the word.
Guesses remaining: 25
Word: --------------------
Next guess? w
There is no w in the word.
Guesses remaining: 24
Word: --------------------
Next guess? e
There is no e in the word.
Guesses remaining: 23
Word: --------------------
Next guess? r
Good guess!
Guesses remaining: 23
Word: ---r--------r-------
Next guess? t
Good guess!
Guesses remaining: 23
Word: --tr------t-r---t---
Next guess? y
There is no y in the word.
Guesses remaining: 22
Word: --tr------t-r---t---
Next guess? u
Good guess!
Guesses remaining: 22
Word: u-tr------tur---t---
Next guess? i
Good guess!
Guesses remaining: 22
Word: u-tr--i-i-turi--ti--
Next guess? o
Good guess!
Guesses remaining: 22
Word: u-tr--i-i-turi--tio-
Next guess? p
There is no p in the word.
Guesses remaining: 21
Word: u-tr--i-i-turi--tio-
Next guess? a
Good guess!
Guesses remaining: 21
Word: u-tra-i-iaturi-atio-
Next guess? s
There is no s in the word.
Guesses remaining: 20
Word: u-tra-i-iaturi-atio-
Next guess? d
There is no d in the word.
Guesses remaining: 19
Word: u-tra-i-iaturi-atio-
Next guess? f
There is no f in the word.
Guesses remaining: 18
Word: u-tra-i-iaturi-atio-
Next guess? g
There is no g in the word.
Guesses remaining: 17
Word: u-tra-i-iaturi-atio-
Next guess? h
There is no h in the word.
Guesses remaining: 16
Word: u-tra-i-iaturi-atio-
Next guess? j
There is no j in the word.
Guesses remaining: 15
Word: u-tra-i-iaturi-atio-
Next guess? k
There is no k in the word.
Guesses remaining: 14
Word: u-tra-i-iaturi-atio-
Next guess? l
Good guess!
Guesses remaining: 14
Word: ultra-i-iaturi-atio-
Next guess? z
Good guess!
Guesses remaining: 14
Word: ultra-i-iaturizatio-
Next guess? x
There is no x in the word.
Guesses remaining: 13
Word: ultra-i-iaturizatio-
Next guess? c
There is no c in the word.
Guesses remaining: 12
Word: ultra-i-iaturizatio-
Next guess? v
There is no v in the word.
Guesses remaining: 11
Word: ultra-i-iaturizatio-
Next guess? b
There is no b in the word.
Guesses remaining: 10
Word: ultra-i-iaturizatio-
Next guess? n
Good guess!
Guesses remaining: 10
Word: ultra-iniaturization
Next guess? m
Good guess!
You win! The word was ultraminiaturization.
Play another round (y/n)? n
```

## Author(s)

| Name                    | GitHub                                     | Email
| ----------------------- | ------------------------------------------ | -------------------------
| Xinzheng (Kevin) Xu     | [kevinxu993](https://github.com/kevinxu993)| xuxinzheng24@gmail.com

## Thoughts and future improvements

* Since this is a rather simple beginner's project, no further improvements will be made.

## Contributing to this project

1. Fork it [![GitHub forks](https://img.shields.io/github/forks/kevinxu993/Wheel-of-Misfortune.svg?style=social&label=Fork&maxAge=2592000&)](https://github.com/kevinxu993/Wheel-of-Misfortune/fork)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -m 'Add some feature'`)
4. Push to your feature branch (`git push origin my-new-feature`)
5. Create a new Pull Request

Details are described [here](https://git-scm.com/book/en/v2/GitHub-Contributing-to-a-Project).

## Bug Reporting [![GitHub issues](https://img.shields.io/github/issues/kevinxu993/Wheel-of-Misfortune.svg?)](https://github.com/kevinxu993/Wheel-of-Misfortune/issues/)

Please click `issue` button above↑ to report any issues related to this project  
OR you can shoot an email to <xuxinzheng24@gmail.com>

## License
This project is released under GNU General Public License v3.0 - see [LICENSE](LICENSE) file for more details.

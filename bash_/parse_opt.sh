#!/bin/bash

__help="
Command: This is only sample test.
  Description of flags:
  -v, --verbose
  -a, --file_a <path>           Description of the flag and params
  -b, --file_b <path>           Description of the flag and params
  -c, --file_c <optional_path>  Description of the flag and params
--
"


## Example for getops

file_isvalid(){
    [[ -f "$1" ]] || echo "File is not valid" >&2 && exit
}

## Test shift
## What is the behaviour of the shift with the last arg?
## Empty or no more shift?
test_shift(){
    while(true) ; do
        echo "$1"
        shift
    done
}

VERBOSE=false
FILE_A=false
FILE_B=false
FILE_C="default_file"
## getopts support options short, long and with,w+/o or optional arguments
## The colon is specifies the argument param
## No colon: There's no parameter for this flag
## one colon: This flag has a parameter
## two colons: This flag has an optional parameter
##
## Is the same for short and long options

#test_shift a b c e d f r g t h z j u k

OPTS=$( getopt -o hva:b:c:: --long help,verbose,file_a:,file_b:,file_c:: -- "$@" )

while(true) ; do
    case "$1" in
    -v|--verbose) VERBOSE=true shift ;; ## shift moves the parameters $1 is dropped, $2->$1
    -a|--file_a) FILE_A="$2" shift 2 ;; ## When a flag contains a parameter 2 shifts are needed
    -b|--file_b) FILE_B="$1" shift 2 ;;
    -c|--file_c)
        echo $1
        echo $2
        case "$2" in
            "") FILE_C="default_file" ;;
            *) FILE_C="$2" ;;
        esac
        echo ".."
        shift 2
    ;;
    --) shift break ;; ## The -- means the end of flag commands
    -h|--help|*) echo "$__help" ; break ;;
    "") break ;; ## end of flags
    esac
done

echo "VERBOSE=$VERBOSE"
echo "FILE_A=$FILE_A"
echo "FILE_B=$FILE_B"
echo "FILE_C=$FILE_C"

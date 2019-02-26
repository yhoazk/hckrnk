TIMEOUT=50
## select from array


init_do(){
  return 0
}

stateA_do(){
  echo "State A"
  ip a
  return 0
}

stateB_do(){
  echo "State B"
  # Creating a sub shell, and exiting from it
  # The FSM does not end, a subshell is created with parenthesis
  ( exit )
  return 0
}
## echo vs return
stateC_do(){
  echo "State C"
  # mute block of comments
  {
    # if we need to make sure that all this commands
    # execute correctly use set -e and the program
    # will end if any of these fail, is not possible
    # to check the $? as the script just ends
    #set -e
    echo "xxx"; # semicolons are needed...officially
    echo "xxx";
    echo "xxx";
    false;
  } > /dev/null # when commands are groupes the output can be redirectet
  # at once

 return 0
}


fsm(){
    while [[ "$STATE" != "done" && "$TIMEOUT" -gt "0" ]]; do
        case $STATE in
            init|"")
            echo "Init State" >&2
            init_do
            STATE=$( [[ $? -ne "0" ]] && echo "stateA" || echo "stateB")
            ;;
            stateA)
            stateA_do
            STATE=$( [[ $? -ne "0" ]] && echo "stateA" || echo "stateB")
            ;;
            stateB)
            stateB_do
            STATE=$( [[ $? -ne "0" ]] && echo "stateB" || echo "stateC")
            ;;
            stateC)
            stateC_do
            TIMEOUT=$(( $TIMEOUT -1 ))
            STATE=$( [[ $? -ne "0" ]] && echo "done" || echo "stateB")
            ;;
            done)
            ;;
            *)
            # Default
            echo "default"
            STATE="init"
            ;;
        esac
    done
  return $( [[ $TIMEOUT -gt 0 ]] )
}

fsm || echo "FSM failed"

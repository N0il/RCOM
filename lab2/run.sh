xterm -hold -fa 'Monospace' -fs 14 -title "Receiver" -e "echo 'Issuing command ./receiver /dev/ttyS11'; ./receiver /dev/ttyS11" &
xterm -bg 'light grey' -fg black -hold -fa 'Monospace' -fs 14 -title "Transmitter" -e "echo 'Issuing command ./transmitter /dev/ttyS10 pinguim.gif'; ./transmitter /dev/ttyS10 pinguim.gif" 
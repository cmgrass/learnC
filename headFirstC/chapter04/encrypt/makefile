CFLAGS=-Wall -g

program_message_hider: clean_message_hider
	gcc message_hider.c encrypt.c -o message_hider

program_dataFileHider: clean_dataFileHider
	gcc dataFileHider.c encrypt.c -o dataFileHider

clean_message_hider:
	rm -rf message_hider

clean_dataFileHider:
	rm -rf dataFileHider

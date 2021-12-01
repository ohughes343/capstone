# capstone
This arduino code controls a set of 4 relays which are connected to an impact driver.
When relays 2 and 3 are turned on, the driver turns forwards
When relays 1 and 4 are turned on, the driver turns backwards

relay_switch.ino tells the driver to alternate between forwards and backwards, waiting 2 
seconds after one turn has completed to start the next.
When the driver is commanded to turn, it turns until it detects a magnet or until 0.02 seconds 
have passed, whichever comes first.

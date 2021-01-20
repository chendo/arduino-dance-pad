# Dance Pad for Arduino Leonardo

This code will enable an Arduino (tested with Leonardo) to convert a debounced completed circuit on digital pins to a key press.

I wrote this to replace a broken controller box for a metal pad I bought years ago. You should be able to adapt this code to work for switches that complete an electrical circuit.

My first Arduino project!

## Requirements

* Keyboard - stdlib
* Bounce2, downloadable with Arduino IDE

## Notes

* Debounce threshold is 50ms by default
* `loop()` is being executed about 14,000 times per second with a rough benchmark, so theoretically 14kHz poll rate
* Unsure what USB poll rate

## Future ideas

Pull requests welcome!

* LED support
* Load cell support

# License

MIT

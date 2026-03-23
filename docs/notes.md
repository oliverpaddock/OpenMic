## Todo

| kicad file    | schematic done | simulated | tested | test board done |
| ------------- | -------------- | --------- | ------ | --------------- |
| om_ADC        |                |           |        |                 |
| om_clip       | yes            |           |        |                 |
| om_crossfader | yes            | yes       |        |                 |
| om_input      | yes            | yes       |        |                 |
| om_lineout    |                |           |        |                 |
| om_phantom    | yes            |           | yes    |                 |
| om_phonesout  |                |           |        |                 |

### Next steps
1. Finish all schematics and add annotations
2. Test breadboard circuits
3. Design boards for pcb testing



### Gain stages
inputs
    -> gain stage (nom -2dBu/phase)
        -> -16dB pad (-18dBu)
            -> ADC (-18dBu)
        -> direct monitoring (-2dBu)

DAC (nom -18dBu)
    -> +16dB pad (-2dBu)
        -> mix with direct monitoring (-2dBu)
            -> line output (+4dBu differential) with attenuator knob
            -> headphone output (+4dBu differential) with attenuator knob
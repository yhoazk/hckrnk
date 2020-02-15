
function show() {
    for (let index = 0; index < 5; index++) {
        current = tim[index]
        h_bar(current, index)
    }
}
function h_bar(state: number, row: number) {
    for (let index2 = 0; index2 < 5; index2++) {
        if (index2 < state) {
            led.plot(index2, row)
        } else {
            led.unplot(index2, row)
        }
    }
}
let end = false
let clear = [false, false, false, false, false]
function dec() {
    if (!end) {
        if ((test_count % (5)) == 0 && test_count != 0) {
            serial.writeLine("tim1")
            tim[1] = clear[1] ? 0 : (1 + tim[1])
            clear[1] = false
            clear[0] = true
        }
        if (test_count % (5 * 5) == 0 && test_count != 0) {
            tim[2] = clear[2] ? 0 : (1 + tim[2])
            clear[2] = false
            clear[1] = true
        }
        if (test_count % (5 * 5 * 5) == 0 && test_count != 0) {
            tim[3] = clear[3] ? 0 : (1 + tim[3])
            clear[3] = false
            clear[2] = true
        }
        if (test_count % (5 * 5 * 5 * 5) == 0 && test_count != 0) {
            tim[4] = clear[4] ? 0 : (1 + tim[4])
            clear[4] = false
            clear[3] = true
        }
        tim[0] = clear[0] ? 0 : (1 + tim[0])
        clear[0] = false
        end = tim[4] == 5
        serial.writeNumbers(tim)
    } else {
        basic.clearScreen()
        basic.showIcon(IconNames.Skull)
        return false
    }
    return true
}

input.onButtonPressed(Button.B, function () {
    if (single) {
        // led.plotAll()
        single = false
    }
    h_bar(test_count, 0)
    test_count = kk ? 1 + test_count : 0
    let g = kk ? "sicaca" : "nocaca"
    serial.writeValue(g, 0)
})
let kk = false
input.onButtonPressed(Button.A, function () {
    // led.plot(press_count, mod5)
    led.setBrightness(158)
    //serial.writeNumber(test_count)
    kk = !kk
    //h_bar(test_count, 0)
    while (true) {
        control.waitMicros(800000)
        show()
        if (dec() == false) {
            break
        }
        test_count += 1
    }


})
let current = 0
let test_count = 0
let single = false

let press_count = 0
let tim = [0, 0, 0, 0, 0]



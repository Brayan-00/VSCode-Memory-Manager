// Import dependencies
const ffi = require("ffi-napi");

// Import math library
const mathLibrary = new ffi.Library("./libpruebaVS", {
    "Subtract": [
        "int", ["int", "int"]
    ],
    "Add": [
        "int", ["int", "int"]
    ]
});

console.log(mathLibrary.Subtract(15, 5));

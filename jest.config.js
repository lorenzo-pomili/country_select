module.exports = {
  verbose: true,
  testURL: "http://localhost/",
  testMatch: [ '**/__tests__/**/*.js?(x)', '**/?(*_)(spec|test).bs.js?(x)' ],
  moduleNameMapper: {
    "\\.(css|less)$": "identity-obj-proxy"
  }
}

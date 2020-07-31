#!/usr/bin/node
/** Prints all characters of a Star Wars movie **/

const request = require('request');
const url = `https://swapi-api.hbtn.io/api/films/${process.argv[2]}`;

function printCharacters (chars, i) {
  if (i === chars.length) return;
  request(chars[i], function (err, response, body) {
    if (err) {
      console.log(err);
    } else {
      console.log(JSON.parse(body).name);
      printCharacters(chars, i + 1);
    }
  });
}

request(url, (err, response, body) => {
  if (err) {
    console.log(err);
  } else {
    const chars = JSON.parse(body).characters;
    printCharacters(chars, 0);
  }
});

#!/usr/bin/node
const request = require('request');
const film = process.argv[2];
const url = 'https://swapi-api.hbtn.io/api/films/' + film;

const caller = function () {
  request(url, function (error, mv, body) {
    if (error) { throw error; }
    ender(JSON.parse(body).characters, 0);
  });
};

const ender = function (characters, i) {
  if (characters.length === i) { return; }

  request(characters[i], function (error, mv, body) {
    if (error) { throw error; }

    console.log(JSON.parse(body).name);
    ender(characters, ++i);
  });
};

caller();

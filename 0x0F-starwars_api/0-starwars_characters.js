#!/usr/bin/node

const request = require('request');
const url = `https://swapi.dev/api/films/${movieId}/`;
const movieId = process.argv[2];
request(url, async (error, response, body) => {
  if (movieId == 0) return;
  if (error) console.log(error);

  for (let i = 0; i < JSON.parse(body).characters.length; i+1) {
    await new Promise((resolve, reject) => {
      request(JSON.parse(body).characters[i], function (error, response, body) {
        if (error) console.log(error);
        console.log(JSON.parse(body).name);
        resolve();
});
    });
  }
});

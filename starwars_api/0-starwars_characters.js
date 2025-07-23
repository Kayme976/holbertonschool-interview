#!/usr/bin/node

const request = require('request');

function fetchCharacter (url) {
  return new Promise((resolve, reject) => {
    request(url, (error, response, body) => {
      if (error) return reject(error);
      resolve(JSON.parse(body).name);
    });
  });
}

async function getCharacterNames (movieId) {
  const movieUrl = `https://swapi-api.hbtn.io/api/films/${movieId}/`;

  request(movieUrl, async (error, response, body) => {
    if (error) {
      console.error(error);
      return;
    }

    const movieData = JSON.parse(body);
    const characterUrls = movieData.characters;

    // Fetch characters in sequence to maintain order
    for (const url of characterUrls) {
      try {
        const name = await fetchCharacter(url);
        console.log(name);
      } catch (err) {
        console.error(err);
      }
    }
  });
}

// Get the Movie ID from the command line argument
const movieId = process.argv[2];

getCharacterNames(movieId);

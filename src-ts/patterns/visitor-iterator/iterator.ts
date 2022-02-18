import axios, { AxiosResponse } from 'axios';

const POKE_API = 'https://pokeapi.co/api/v2/pokemon';

async function* iterateResult<DataType>(baseUrl: string) {
  let nextUrl: string | undefined = baseUrl;

  do {
    // eslint-disable-next-line no-await-in-loop
    const { data } = (await axios.get(nextUrl)) as AxiosResponse<{
      next?: string;
      results: DataType[];
    }>;

    yield* data.results;
    nextUrl = data.next;
  } while (nextUrl !== undefined);
}

interface Pokemon {
  name: string;
  url: string;
}

(async () => {
  for await (const result of iterateResult<Pokemon>(POKE_API)) {
    console.log(result);
    if (result.name === 'pikachu') break;
  }
})();

import axios, { AxiosResponse } from 'axios';

const POKE_API = 'https://pokeapi.co/api/v2/pokemon';

const visit = async <DataType>(baseUrl: string, visitor: (results: DataType[]) => void) => {
  let nextUrl: string | undefined = baseUrl;

  do {
    // eslint-disable-next-line no-await-in-loop
    const response = (await axios.get(nextUrl)) as AxiosResponse<{
      next?: string;
      results: DataType[];
    }>;

    visitor(response.data.results);
    nextUrl = response.data.next;
  } while (nextUrl !== undefined);
};

interface Pokemon {
  name: string;
  url: string;
}

visit<Pokemon>(POKE_API, (results) => {
  console.log(results);
});

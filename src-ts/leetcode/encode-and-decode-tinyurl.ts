const urlMap: Record<string, string> = {};

const createUId = () => `_${Math.random().toString(36).slice(2, 9)}`;

/**
 * Encodes a URL to a shortened URL.
 */
function encode(longUrl: string): string {
  const uId = createUId();

  urlMap[uId] = longUrl;

  return `http://tinyurl.com/${uId}`;
}

/**
 * Decodes a shortened URL to its original URL.
 */
function decode(shortUrl: string): string {
  const [, uId] = shortUrl.split('m/');

  return urlMap[uId];
}

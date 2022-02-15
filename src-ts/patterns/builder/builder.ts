import fs from 'fs';

interface IFileReader {
  isJSONFile(filePath: string): boolean;
  readMarkdownFile(filePath: string): string;
  readJSONFile(filePath: string): unknown;
}

const scanFiles = (dirPath: string, reader: IFileReader) =>
  fs.readdirSync(dirPath).reduce<Record<string, unknown>>((acc, fileName) => {
    if (reader.isJSONFile(fileName)) {
      acc[fileName] = reader.readJSONFile(`${dirPath}/${fileName}`);
    } else {
      acc[fileName] = reader.readMarkdownFile(`${dirPath}/${fileName}`);
    }

    return acc;
  }, {});

const fileReader: IFileReader = {
  isJSONFile: (filePath: string): boolean => filePath.endsWith('.json'),
  readMarkdownFile: (filePath: string): string => fs.readFileSync(filePath, 'utf8').toString(),
  readJSONFile: (filePath: string): unknown =>
    JSON.parse(fs.readFileSync(filePath, 'utf8').toString()),
};

console.log(scanFiles('./data', fileReader));

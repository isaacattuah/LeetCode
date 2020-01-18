def getDirectory(lang: str, problemID: str, extension: str) -> str:
    return './solutions/' + lang + '/' + problemID + extension


def getMkdocsPathName(i: int) -> str:
    return str(i + 1).zfill(4) + '-' + str(i + 100).zfill(4)


def getMkdocsFileName(i: int) -> str:
    return str(i + 1).zfill(4) + '-' + str(i + 10).zfill(4) + '.md'

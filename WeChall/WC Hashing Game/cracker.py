#!/usr/bin/env python2

from hashlib import md5, sha1

wc3 = set((
    'f2ac27bd046b327650691ed6a30fb9e2',
    'b15b63943b7a05cc8f0701163f1691e1',
    'a26ff306525d12ba6028dc03e5bc41a9',
    '76faebc6e506638d79af29e229774330',
    '39fabbeaa613ca71e47325afd40e13b2',
    '7670f4160d7e560204550f5d30a22b24',
    '6859cb2155815badc7e99dbbc1c89271',
    '8e0d02b497507d5fd9d78de1038655bf',
    'a93ebf7abf9d00d1067f4b5a4efc2da1',
    '26765a5c67b665af7d8d092899ea7758',
    'd70ac297cb2a8c5602acbea98557766c',
    '22b5890cdc55dabba0fc1ae597c3399a',
    '0bba68cb838f3c97ce0bea87c1efb524',
    '232198ee431325f50062d0921a3b594c',
    'a89eb515d9f9bbc4aade0601c3667e87',
    '9129296563206aefc1047a7dfb3b8c3e',
    '2c854e1b8dc5afb4fa1c013052f817f0',
))

wc4 = set((
    'cf2fff4ab4fb050d1a5039bb02476b03b57c73cfUyOf',
    '98216cb302c19bed029d116f53c74dc70264250cXbfc',
    '8ab7d658af5f26088365fc5951dfb9c4b260aa1fLDuv',
    '754551a14dd65bbc66c0925bc87bc871f0603de0NJna',
    '627762e4b64761b57c2182a70b8caa3a0079d5eewdmQ',
    '38bc01523f11bff9b684bec124ac48caebf4ff98x9Nx',
    '30c9d6ace4515657dcd4253dd2e6c29c90959739gH9W',
    'c3bacc76a5caab8ba81aef582f97a58c744e91de9MIU',
    'bfe65303b839ad7322b4bd6bf03e27e431b04a1abnZY',
    'ea88591525f11aa3b34737fd02d2a40f4e6f268eo500',
    '07c03cd11627f42a12b61bd20d09a5d2b5d14daezlmc',
    '9d0c776fb694c9f0b192b38e73820c58874c8a45Vzdh',
    '7beba79084b510a63d2ab85274b376682956aaa0DpX1',
    '5202a220cb9e32ab64b67d20a0e9718ed4a39fc9oBou',
    '64879c46705f3c596923feb37df9e8b1a2415bdf8oh8',
    '1523facfd6e1107b22d4d8c332e5348f98b87aa51QS2',
    '0f5fe6b87cfcb3ba788daa2ed9e38e32d06ed0c93HRi',
))

w3result = []
w4result = []


def hashgame_wc3(plaintext):
    return md5(md5(plaintext).hexdigest() + 'zomgsalt').hexdigest()


def hashgame_wc4_match(password, wc4hash):
    salt = wc4hash[-4:]
    hash = sha1('zomgsalt4' + password + salt + 'zomgsalt4').hexdigest()
    return hash == wc4hash[:-4]

if __name__ == '__main__':
    with open('dic') as dic:
        for line in dic:
            word = line.strip()
            wc3hash = hashgame_wc3(word)
            if wc3hash in wc3:
                w3result.append((word, wc3hash))
            for wc4hash in wc4:
                if hashgame_wc4_match(word, wc4hash):
                    w4result.append((word, wc4hash))
                    break
    for word, wc3hash in w3result: print wc3hash, word
    for word, wc4hash in w4result: print wc4hash, word

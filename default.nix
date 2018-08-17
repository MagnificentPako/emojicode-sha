with import <nixpkgs> {};

stdenv.mkDerivation {
    name = "emojicode-sha";
    src  = ./.;
    buildInputs = [ cmake openssl (import "/etc/nixos/pkgs/emojicode") ];
}
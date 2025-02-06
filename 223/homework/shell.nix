{ pkgs ? import <nixpkgs> { } }:

let
  texlive = pkgs.texliveBasic.withPackages (ps: with ps; [
    enumitem
    fancyvrb
    minted
    pkgs.python3Packages.pygments
    upquote
  ]);
in
pkgs.mkShell {
  buildInputs = with pkgs; [
    tex-fmt
    texlab
    texlive
  ];
}

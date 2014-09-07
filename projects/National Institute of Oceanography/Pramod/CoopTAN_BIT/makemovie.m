function makemovie(F,filename,playmovie)

if playmovie
    [h, w, p] = size(F(1).cdata);
    hf = figure;
    % resize figure based on frame's w x h, and place at (150, 150)
    set(hf,'Position', [150 150 w h]);
    % Place frames at bottom left
    movie(hf,F,1,30,[0 0 0 0]);%
end
movie2avi(F, filename, 'compression', 'None');
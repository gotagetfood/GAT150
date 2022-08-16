#include "Texture.h" 
#include "Renderer.h" 
#include "Core/Logger.h"
#include "Engine.h"
#include <SDL.h> 
#include <SDL_image.h> 

namespace towr
{
    Texture::~Texture()
    {
        // !! if texture not null SDL_DestroyTexture 
        if (m_texture != nullptr) SDL_DestroyTexture(m_texture);
    }

    bool Texture::Create(std::string filename, ...)
    {
        // va_list - type to hold information about variable arguments 
        va_list args;

        // va_start - enables access to variadic function arguments 
        va_start(args, filename);

        // va_arg - accesses the next variadic function arguments 
        Renderer& renderer = va_arg(args, Renderer);

        // va_end - ends traversal of the variadic function arguments 
        va_end(args);

        // create texture (returns true/false if successful) 
        return Create(renderer, filename);
    }

    bool Texture::Create(Renderer& renderer, const std::string& filename)
    {
        // load surface 
        SDL_Surface* surface = IMG_Load(filename.c_str()); 
        if (surface == nullptr) {
            LOG(SDL_GetError());
            return false;
            //g_logger.Log("error loading %s", filename.c_str());
        }

        // create texture
        m_texture = SDL_CreateTextureFromSurface(renderer.m_renderer, surface);
        if (m_texture == nullptr) {
            LOG(SDL_GetError()); 
            SDL_FreeSurface(surface);
            return false;
            //g_logger.Log("error loading %s", filename.c_str());
        }
        SDL_FreeSurface(surface);

        return true;
    }

    towr::Vector2 Texture::GetSize() const
    {
        SDL_Point point;
        SDL_QueryTexture(m_texture, nullptr, nullptr, &point.x, &point.y);

        return Vector2(point.x,point.y);  
    }
}
